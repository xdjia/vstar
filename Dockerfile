# Use an official Python runtime as a parent image
FROM python:3.12

# Avoid prompts from apt during build
ARG DEBIAN_FRONTEND=noninteractive

# Update package lists and install a package (e.g., curl)
RUN apt update && \
    apt install -y zsh g++ antlr4 libantlr4-runtime-dev && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /usr/src/vstar

# Copy the current directory contents into the container at /usr/src/vstar
COPY . .

# Build the binaries for grammar recognizing.
RUN chmod +x ./setup_bin.sh
RUN zsh ./setup_bin.sh

RUN chmod +x setup_arvada.sh
RUN zsh ./setup_arvada.sh

RUN chmod +x setup_glade.sh
RUN zsh ./setup_glade.sh

# Install VStar
RUN pip install -e .

ENTRYPOINT ["python", "run_benchmark.py"]

import matplotlib.pyplot as plt
from collections import defaultdict
import pickle

# Initialize the defaultdict
data = defaultdict(list)

# List of files (representing different datasets)
files = ["json", "lisp", "while", "xml", "mathexpr"]

# Load data from pickle files
for file in files:
    with open('num_states_' + file, 'rb') as f:
        data[file] = pickle.load(f)

# Set figure size for a 16:9 aspect ratio suitable for Marp slides
fig_width = 20  # inches
fig_height = 11.25  # inches

# Create subplots - a 2x3 grid; will leave one subplot empty
fig, axes = plt.subplots(2, 3, figsize=(fig_width, fig_height))  # Set grid and figure size for slide

# Flatten the axes array for easier indexing (since axes is a 2D array)
axes = axes.flatten()

# Plot each dataset in a separate subplot
for i, file in enumerate(files):
    # Assuming each file contains data as tuples of (y, x) for plotting
    y, x = zip(*data[file])  # Unpack x and y data from the loaded tuples
    axes[i].plot(x, y, linestyle='-')  # Plot with markers
    axes[i].set_title(file, fontsize=18)  # Set the title for each subplot, bigger font for slide
    axes[i].grid(True)
    axes[i].ticklabel_format(style='sci', axis='x', scilimits=(3, 3))  # Force scientific notation at 1e3

# Hide the last (empty) subplot if needed (since it's a 2x3 grid but only 5 datasets)
if len(files) < len(axes):
    for i in range(len(files), len(axes)):
        axes[i].axis('off')  # Turn off the unused subplot

# Set a common x-axis label and y-axis label for all subplots
fig.supxlabel('Number of Membership Queries', fontsize=18)  # Common x-axis label, larger font for slides
fig.supylabel('Number of VPA States', fontsize=18)  # Common y-axis label, larger font for slides

# Remove the suptitle for this slide, but you could re-enable if needed
# fig.suptitle('VPA States vs Number of Membership Queries', fontsize=20)

# Tight layout to prevent overlap between subplots
plt.tight_layout(rect=(0, 0, 1.1, 1.3))  # Adjust layout for 16:9 aspect ratio

# Save the figure with all subplots as a high-resolution PNG for Marp slides
plt.savefig('combined_subplots_marp_slide.png', format='png', bbox_inches='tight', dpi=96)

# Optional: save as PDF as well if needed
plt.savefig('combined_subplots_marp_slide.pdf', format='pdf', bbox_inches='tight')

# Show the plot (optional if you're just saving it)
# plt.show()
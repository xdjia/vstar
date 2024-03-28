from setuptools import setup, find_packages

setup(
    name='vstar',
    version='1.0',
    packages=find_packages(),
    install_requires=[
        'tqdm',
        'termcolor',
        'lark',
        'numpy',
    ]
)
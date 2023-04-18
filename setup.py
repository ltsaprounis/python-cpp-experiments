__author__ = ["Leonidas Tsaprounis"]

from setuptools import setup, find_packages
from pycpp.utils import parse_requirements_file

setup(
    name="pycpp",
    version="0.0.0",
    packages=find_packages(),
    description="experiments with cpp python binds",
    author="Leonidas Tsaprounis",
    install_requires=parse_requirements_file("requirements.txt"),
)

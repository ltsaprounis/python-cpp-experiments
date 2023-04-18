"""Utility functions"""

from typing import List


def parse_requirements_file(path: str = None) -> List[str]:
    """Parses the a requirements.txt file to a list
    Parameters
    ----------
    path : str, optional
            path to requirements.txt file, by default None
    Returns
    -------
    List[str]
            e.g. ["pandas==1.0.0", "numpy"]
    """
    reqs = []
    with open(path) as file:
        for line in file:
            line = line.strip("\n")
            if line != "":
                reqs.append(line.strip("\n"))

    return reqs

"""Tests the utils functions"""

import os
from pycpp.utils import parse_requirements_file

TEST_DIR_PATH = os.path.dirname(os.path.realpath(__file__))


def test_parse_requirements_file():
    """Tests the parse_requirements_file function."""
    expected_list = ["numpy==1.0", "pandas==2.0"]
    file_path = os.path.join(TEST_DIR_PATH, "requirements.unit_test.txt")
    assert parse_requirements_file(file_path) == expected_list

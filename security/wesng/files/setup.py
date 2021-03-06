#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

from setuptools import setup
from os import path
from io import open

here = path.abspath(path.dirname(__file__))

with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='wesng',
    version='0.95',
    description='WES-NG is a tool based on the output of Windows\' systeminfo'
    ' utility which provides the list of vulnerabilities the OS is vulnerable'
    ' to, including any exploits for these vulnerabilities.',
    long_description=long_description,
    long_description_content_type='text/markdown',
    url='https://github.com/bitsadmin/wesng',
    author='Arris Huijgen (@bitsadmin)',
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Information Technology',
        'Intended Audience :: System Administrators',
        'Topic :: Security',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
    ],
    py_modules=["wes"],
    python_requires='>=3.4',
    install_requires=['chardet'],
    package_data={
        'CVE': ['CVE.zip'],
    },
    entry_points={
        'console_scripts': [
            'wes=wes:main',
        ],
    },
    project_urls={  # Optional
        'Bug Reports': 'https://github.com/bitsadmin/wesng/issues',
        'Source': 'https://github.com/bitsadmin/wesng/',
    },
)

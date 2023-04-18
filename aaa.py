#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import os


def collect_input():
    files = os.listdir('.')
    for file in files:
        if os.path.isdir(file):
            continue
        print(file)

    return []


submit = False

for arg in sys.argv[1:]:
    if arg == '-s':
        submit = True

inputs = ['test.in']
if submit:
    inputs += collect_input()


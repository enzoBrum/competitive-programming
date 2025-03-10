#!/bin/bash

FILE=${2:-kattis}/$1.cpp

cp template.cpp $FILE

if [ $TERM_PROGRAM = "vscode" ]; then
  code -r $FILE
else
  ${3:-nvim} $FILE
fi

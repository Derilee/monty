#!/bin/bash

# Collect author information
AUTHORS=$(git log --format='%an' | sort -u)

# Generate Authors section in Markdown format
AUTHORS_SECTION="## Authors\n"
for author in $AUTHORS; do
  AUTHORS_SECTION+="* $author\n"
done

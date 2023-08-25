#!/bin/sh

# Generate Authors section in Markdown format
AUTHORS_SECTION="## Authors\n"
git shortlog -se \
  | perl -spe 's/^\s+\d+\s+//' \
  | sed -e '/^CommitSyncScript.*$/d' \
  | while read author; do
      AUTHORS_SECTION="${AUTHORS_SECTION}* ${author}\n"
    done

# Update the README file
awk -v section="$AUTHORS_SECTION" '/## Authors/ {p=1;print;print section} p && !/## Authors/{p=0}' README.md > README_temp.md
mv README_temp.md README.md

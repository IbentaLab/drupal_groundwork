#!/bin/bash

#
# Groundwork Theme Backup Script
#
# This script creates a timestamped backup of the Groundwork theme folder.
# It excludes development files (.git, .vscode, .admin, .backups, .history)
# and creates both a zip archive and an unzipped copy in the .backups folder.
#
# Usage: Run from inside the 'groundwork' directory with ./backup.sh
#

# Check if we're in the correct directory
if [ "$(basename "$PWD")" != "groundwork" ]; then
  echo "⚠️  Please run this script from inside the 'groundwork' directory."
  exit 1
fi

# Go up one directory to the parent of groundwork
cd ..

# Create backups directory inside groundwork if it doesn't exist
mkdir -p groundwork/.backups

# Clean up old backups with the same pattern
echo "Cleaning up old backups..."
rm -f groundwork/.backups/*T*-groundwork.zip
rm -rf groundwork/.backups/*T*-groundwork

# Get current timestamp in local time with timezone abbreviation
TIMESTAMP=$(date +'%Y%m%dT%H%M%S%Z')
FILENAME="groundwork/.backups/${TIMESTAMP}-groundwork.zip"
UNZIP_DIR="groundwork/.backups/${TIMESTAMP}-groundwork"

# Define exclusions
EXCLUDES=(
  -x "groundwork/.git*"
  -x "groundwork/.git/*"
  -x "groundwork/.admin/*"
  -x "groundwork/.backups/*"
  -x "groundwork/.history/*"
  -x "groundwork/.vscode/*"
)

echo "Creating backup: $FILENAME"

# Create the backup zip of the groundwork folder
zip -r "$FILENAME" groundwork "${EXCLUDES[@]}"

if [ $? -eq 0 ]; then
    echo "✅ Backup created successfully: $FILENAME"
    ls -lh "$FILENAME"

    # Unzip the backup
    echo "Unzipping backup to: $UNZIP_DIR"
    unzip -q "$FILENAME" -d "$UNZIP_DIR"

    if [ $? -eq 0 ]; then
        echo "✅ Backup unzipped successfully to: $UNZIP_DIR"
        ls -la "$UNZIP_DIR"
    else
        echo "❌ Unzip failed"
    fi
else
    echo "❌ Backup failed"
    exit 1
fi

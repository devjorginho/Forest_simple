#!/bin/bash

count=1

for file in *.xpm; do
  # Formata o número com dois dígitos, tipo 01, 02...
  new_name=$(printf "idle%02d.xpm" "$count")
  mv -v "$file" "$new_name"
  count=$((count + 1))
  if [ $count -gt 12 ]; then
    break
  fi
done


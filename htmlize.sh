#!/bin/bash -eu

if [[ $# = 0 ]]; then
  style="colorful"
elif [[ $# = 1 ]]; then
  style=$1
else
  echo "Usage: bash $0 [style_name]"
  exit 0
fi

echo "${style}"

while read -d $'\0' file; do
  filename="$(echo "${file}" | sed s/src/html/)"
  filename="${filename%.*}.html"
  echo "${filename}"
  dirname=$(dirname ${filename})
  echo "${dirname}"
  mkdir -p ${dirname}
  pygmentize -O full,style=${style},linenos=1 -o ${filename} ${file}
done < <(find ./src -name "*.cpp" -print0)

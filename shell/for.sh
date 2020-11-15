#!/usr/bin/env bash
# 遍历/etc目录
# shellcheck disable=SC2045
for file in $(ls /etc)
do
  echo "${file}"
done
exit 0
#!/bin/bash

f="version.h"
echo Creating version.h
hash=$(git log -n1 --format=format:"%H")

echo \#ifndef __VCS_TRACK_H__ > $f
echo \#define __VCS_TRACK_H__ >> $f
echo \/\/THIS FILE IS AUTO GENERATED >> $f
echo \/\/DO NOT TRACK THIS FILE WITH THE VCS >> $f
echo \#define GIT_COMMIT_HASH \"$hash\" >> $f

echo \#endif >> $f
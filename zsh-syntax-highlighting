#!/bin/bash

# remove yourself
rm $0

# install zsh-syntax-highlighting
GITHUB_USER="zsh-users"
GITHUB_REPO="zsh-syntax-highlighting"
SOURCE=https://github.com/${GITHUB_USER}/${GITHUB_REPO}.git
TARGET=${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/${GITHUB_REPO}

git clone ${SOURCE} ${TARGET}

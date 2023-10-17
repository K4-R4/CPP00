#!/bin/bash

readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly NC='\033[0m' # No Color

 awk '{ print $2 }' 19920104_091532.log > expected
 ./account | awk '{ print $2 }' > actual
 diff expected actual
 if [ $? -ne 0 ]; then
    printf "${RED}Test failed${NC}\n"
else
    printf "${GREEN}Test passed${NC}\n"
 fi

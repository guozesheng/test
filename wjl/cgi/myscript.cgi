#!/bin/sh

echo "Content-Type: text/plain"

echo

echo "***Environment Variables***"

env

read buf

echo $buf

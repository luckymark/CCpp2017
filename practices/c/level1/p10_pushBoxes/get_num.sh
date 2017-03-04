#!/bin/bash
for(( i = 1; i <= 8; i++))
do
	figlet task_$i > mid$i
done

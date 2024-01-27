#Khushi Gauli
#1002051688
#Python 3.8.10
#Ubuntu 20.04.3

import os
def main():
	total = 0
	total = dirSpace(".")
	print("This is the lide")
def dirSpace(target_directory):
	total_sum = 0
	for entry in os.listdir(target_directory):
		entry_location = os.path.join(target_directory,entry)
		
		if os.path.isFile(entry_location):
			total_sum += os.path.getsize(entry_location)
		if os.path.isdir(entry_location) and entry not in ['.','..']:
			total_sum += dirSpace(entry_location)
			
		return total_sum

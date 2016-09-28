import math

def leftChild(parentIndex):
	return parentIndex * 2 + 1
	

def rightChild(parentIndex):
	return parentIndex * 2 + 2

def parent(childIndex):
	return math.ceil(childIndex / 2 - 1)

def max_heapify(array, index):
# Diagnostics
	print("Running max_heapify", array)

	# First, get left and right indexes with
	# leftChild(index) and rightChild(index).
	left = leftChild(index)
	right = rightChild(index)
	# Then decide which of array[index],
	# array[left] or array[right] is greatest.
	# (Greatest is an index to the greatest value, not the
	# value itself)
	greatest = index 
	if left < len(array) and array[left] > greatest: # Disregard if out of bounds
		greatest = left
	if right < len(array) and array[right] > greatest: # Disregard if out of bounds
		greatest = right
	# If greatest isn't the original index, then
	# exchange array[index] with array[greatest]
	# Then heapify array[greatest]
	if greatest != index:
		array[greatest], array[index] = array[index], array[greatest]
		max_heapify(array, greatest)


def build_max_heap(array):
	nr_branches = math.floor(len(array) / 2) - 1
	for i in range(nr_branches, 0, -1):
		max_heapify(array, i)
	


	




if __name__ == '__main__':
	array = [0, 1, 3, 5, 9, 8, 4, 6]
	print(array)
	
#	for i in range(0, len(array)-1):
#		print("Parent of " + str(i) + " is " + str(parent(i)))
#		print("Left child of " + str(i) + " is " + str(leftChild(i)))
#		print("Right child of " + str(i) + " is " + str(rightChild(i)))
#		print("\n")
	build_max_heap(array)
	print(array)





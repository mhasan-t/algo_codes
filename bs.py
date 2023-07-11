def bs(low, high, nums, target):
    if high==low:
        if nums[high]==target:
            return high
        return -1

    mid = int((high+low)/2)
    if nums[mid]<target:
        return bs(mid+1, high, nums, target)
    return bs(low, mid, nums, target)
    


def bs(low, high, nums, target):
    if high==low:
    	return high

    mid = int((high+low)/2)
    if nums[mid]<target:
        return bs(mid+1, high, nums, target)
    return bs(low, mid, nums, target)


def bs(low, high, nums, target):
    print(low, high)
    if high <= low:
        return high

    mid = int((high+low)/2) + int((high+low) % 2 != 0)
    if nums[mid] > target:
        return bs(low, mid-1, nums, target)
    return bs(mid, high, nums, target)

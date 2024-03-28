def bisect2(xs, x):
    if not xs: raise ValueError

    i, j = 0, len(xs)-1
    if x[1] <= xs[i][1]:
        return i
    if x[1] > xs[j][1]:
        return j+1

    while j - i > 1:
        k = (i+j)//2
        m = xs[k][1]
        if m < x[1]:
            i = k
        else:
            j = k

    return j

def search(nums, target):
    i = bisect2(nums, target)
    if i == len(nums):
        return -1
    if nums[i] == target:
        return i
    return -1


if __name__ == "__main__":
    io = [
        (([-1, 0, 3, 5, 9, 12], 9), 4),
        (([-1, 0, 3, 5, 9, 12], 2), -1)
    ]
    for i, o in io:
        print(search(*i))

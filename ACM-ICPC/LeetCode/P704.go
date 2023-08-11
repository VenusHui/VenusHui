// 704. 二分查找
func search(nums []int, target int) int {
	l, r := 0, len(nums)
	for l < r {
		m := (l + r) / 2
		if nums[m] < target {
			l = m + 1
		} else {
			r = m
		}
	}
	if l >= len(nums) || nums[l] != target {
		return -1
	}
	return l
}

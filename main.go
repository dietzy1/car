package main

import (
	"fmt"
)

type arguments struct {
	cmd      int
	feedback int
	para1    int
	para2    int
}

func main() {
	var arg arguments
	fmt.Scanf("%x %x %x %x", &arg.cmd, &arg.feedback, &arg.para1, &arg.para2)
	sum := calcChecksum(arg)
	fmt.Printf("7E %s %s EF \n", fmt.Sprintf("%x %x %x %x", arg.cmd, arg.feedback, arg.para1, arg.para2), sum)
}

// Checksum (2 bytes) = 0xFFFF – (CMD + Feedback + Para1 + Para2) + 1
func calcChecksum(arg arguments) string {
	ok := 0xFFFF - (arg.cmd + arg.feedback + arg.para1 + arg.para2) + 1
	return fmt.Sprintf("%x %x", ok>>8, ok&0xFF)
}

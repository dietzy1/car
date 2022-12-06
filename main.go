package main

import (
	"fmt"
	"strings"
)

type arguments struct {
	cmd      int
	feedback int
	para1    int
	para2    int
}

/* func main() {
	var arg arguments
	fmt.Scanf("%x %x %x %x", &arg.cmd, &arg.feedback, &arg.para1, &arg.para2)
	sum := calcChecksum(arg)
	fmt.Printf("7E %s %s EF \n", fmt.Sprintf("%x %x %x %x", arg.cmd, arg.feedback, arg.para1, arg.para2), sum)
} */

func main() {
	string := "7E 06 00 00 1E FF DC EF"
	//split the spring by whitespace
	s := strings.Fields(string)
	fmt.Println(s)
	result := fmt.Sprintf("0x%s0x%s0x%s0x%s0x%s0x%s0x%s0x%s ", s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7])
	fmt.Println(result)

}

func formatString() {

}

// Checksum (2 bytes) = 0xFFFF – (CMD + Feedback + Para1 + Para2) + 1
func calcChecksum(arg arguments) string {
	ok := 0xFFFF - (arg.cmd + arg.feedback + arg.para1 + arg.para2) + 1
	return fmt.Sprintf("%x %x", ok>>8, ok&0xFF)
}

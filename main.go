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

func main() {
	var arg arguments
	fmt.Scanf("%x %x %x %x", &arg.cmd, &arg.feedback, &arg.para1, &arg.para2)
	sum := calcChecksum(arg)

	args := [4]string{}
	for i := 0; i < 4; i++ {
		if len(fmt.Sprintf("%x", arg.cmd)) < 2 {
			args[0] = fmt.Sprintf("0%x", arg.cmd)
			fmt.Println(args[0])
		} else {
			args[0] = fmt.Sprintf("%x", arg.cmd)
		}

		if len(fmt.Sprintf("%x", arg.feedback)) < 2 {
			args[1] = fmt.Sprintf("0%x", arg.feedback)
		} else {
			args[1] = fmt.Sprintf("%x", arg.feedback)
		}

		if len(fmt.Sprintf("%x", arg.para1)) < 2 {
			args[2] = fmt.Sprintf("0%x", arg.para1)
		} else {
			args[2] = fmt.Sprintf("%x", arg.para1)
		}

		if len(fmt.Sprintf("%x", arg.para2)) < 2 {
			args[3] = fmt.Sprintf("0%x", arg.para2)
		} else {
			args[3] = fmt.Sprintf("%x", arg.para2)
		}
		for i := 0; i < 4; i++ {
			args[i] = strings.ToUpper(args[i])
		}
	}
	fmt.Printf("{0x7E, %s %s 0xEF} \n", fmt.Sprintf("0x%s, 0x%s, 0x%s, 0x%s,", args[0], args[1], args[2], args[3]), sum)
}

//char array[8] = {0x7E, 0x03, 0x00, 0x00, 0x02, 0xFF, 0xFB, 0xEF};

// Checksum (2 bytes) = 0xFFFF – (CMD + Feedback + Para1 + Para2) + 1
func calcChecksum(arg arguments) string {
	ok := 0xFFFF - (arg.cmd + arg.feedback + arg.para1 + arg.para2) + 1
	str1, str2 := strings.ToUpper(fmt.Sprintf("%x", ok>>8)), strings.ToUpper(fmt.Sprintf("%x", ok&0xFF))
	return fmt.Sprintf("0x%s 0x%s", str1, str2)
}

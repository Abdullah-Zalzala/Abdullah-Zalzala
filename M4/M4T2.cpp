/*
Abdullah Zalzala
M4T2.cpp
10/22/2025
*/
// i used my m3lab2 as a reference to help me with this lab

// i used chat gpt to help me convert my c++ code into a twee file
// i had to go through about 4 iterations with chat gpt to get the correct output
//the first time the file type was wrong
//the second time i had to specify sugarcube format
//the third time i had to tell it to go in and fix the output bevause it would always reset to default values
//the fourth time is when everything was correct

// all paths work and are playable


// this is my exported twee file
/*
:: StoryTitle
CYOA: Teacher or Hunter (SugarCube)


:: StoryData
{
  "ifid": "5E1D3B8A-E3FC-4F7D-9A8E-ADVENTURE-001",
  "format": "SugarCube",
  "format-version": "2.37.3",
  "start": "Start",
  "zoom": 1
}


:: Combat {"position":"25,150","size":"100,100"}
You are fighting a **barbarian**!

Enter your values:

* Roll: <<textbox "$roll" "">>
* Attack bonus: <<textbox "$bonus" "">>
* Enemy armor class: <<textbox "$ac" "">>

<<button "Resolve Attack">>
	<<set _roll = Number($roll)>>
	<<set _bonus = Number($bonus)>>
	<<set _ac = Number($ac)>>
	<<if Number.isNaN(_roll) or Number.isNaN(_bonus) or Number.isNaN(_ac)>>
		<<goto "Combat: Invalid Input">>
	<<else>>
		<<set _total = _roll + _bonus>>
		<<if _total >= _ac>>
			<<goto "Combat: Hit">>
		<<else>>
			<<goto "Combat: Miss">>
		<</if>>
	<</if>>
<</button>>

[[Back to start->Start]]


:: Combat: Hit {"position":"275,150","size":"100,100"}
**Hit!**  
(Your roll + bonus ≥ enemy AC.)

Again?
* [[Yes (roll again)->Combat]]
* [[No (back to start)->Start]]


:: Combat: Invalid Input {"position":"150,150","size":"100,100"}
One or more inputs weren't numbers. Please try again.
* [[Re-enter combat values->Combat]]
* [[Back to start->Start]]


:: Combat: Miss {"position":"400,150","size":"100,100"}
**Miss!**  
(Your roll + bonus < enemy AC.)

Again?
* [[Yes (roll again)->Combat]]
* [[No (back to start)->Start]]


:: Grade Check {"position":"400,25","size":"100,100"}
<<if Number.isNaN($n)>>
The input wasn't a number. Please try again.
[[Try again->Teacher Path]]
<<elseif $n >= 100>>
<<goto "Result: A++">>
<<elseif $n >= 90>>
<<goto "Result: A">>
<<elseif $n >= 80>>
<<goto "Result: B">>
<<elseif $n >= 70>>
<<goto "Result: C">>
<<elseif $n >= 60>>
<<goto "Result: D">>
<<else>>
<<goto "Result: F">>
<</if>>


:: Result: A {"position":"650,25","size":"100,100"}
A number grade of **<<print $n>>** is a(n) **A**.
* [[Grade another->Teacher Path]]
* [[Back to start->Start]]


:: Result: A++ {"position":"525,25","size":"100,100"}
A number grade of **<<print $n>>** is a(n) **A++**.
* [[Grade another->Teacher Path]]
* [[Back to start->Start]]


:: Result: B {"position":"775,25","size":"100,100"}
A number grade of **<<print $n>>** is a **B**.
* [[Grade another->Teacher Path]]
* [[Back to start->Start]]


:: Result: C {"position":"900,25","size":"100,100"}
A number grade of **<<print $n>>** is a **C**.
* [[Grade another->Teacher Path]]
* [[Back to start->Start]]


:: Result: D {"position":"1025,25","size":"100,100"}
A number grade of **<<print $n>>** is a **D**.
* [[Grade another->Teacher Path]]
* [[Back to start->Start]]


:: Result: F {"position":"1150,25","size":"100,100"}
A number grade of **<<print $n>>** is an **F**.
* [[Grade another->Teacher Path]]
* [[Back to start->Start]]


:: Start [start] {"position":"150,25","size":"100,100"}
Are you a **teacher** or a **hunter**?

* [[teacher->Teacher Path]]
* [[hunter->Combat]]


:: StoryInit {"position":"25,25","size":"100,100"}
<<set $role = "">>
<<set $num = "">>
<<set $n = 0>>
<<set $letter = "">>
<<set $roll = "">>
<<set $bonus = "">>
<<set $ac = "">>


:: Teacher Path {"position":"275,25","size":"100,100"}
You chose **teacher**.

Enter a number grade between **0 and 100**:

<<textbox "$num" "">>
<<button "Submit">>
	<<set $n = Number($num)>>
	<<goto "Grade Check">>
<</button>>

[[Back to start->Start]]

*/
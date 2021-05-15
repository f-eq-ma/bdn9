#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

F16::
	DetectHiddenWindows , On 
	ControlSend , ahk_parent, ^{SPACE}, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return
	
F19::
	DetectHiddenWindows , On 
	ControlSend , ahk_parent, ^{right}, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return
	
F14::
	DetectHiddenWindows , On 
	ControlSend , ahk_parent, ^{left}, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return
	
;Numpad8::
;	SoundSet, +5
;	return
	
;Numpad2::
;	SoundSet, -5
;	return
	
F17::
	DetectHiddenWindows , On 
	ControlSend , ahk_parent, {shift}^M, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return
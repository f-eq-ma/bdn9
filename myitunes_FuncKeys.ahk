;/* Copyright 2021 Robert Hayden
; *
; * This program is free software: you can redistribute it and/or modify
; * it under the terms of the GNU General Public License as published by
; * the Free Software Foundation, either version 2 of the License, or
; * (at your option) any later version.
; *
; * This program is distributed in the hope that it will be useful,
; * but WITHOUT ANY WARRANTY; without even the implied warranty of
; * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; * GNU General Public License for more details.
; *
; * You should have received a copy of the GNU General Public License
; * along with this program.  If not, see <http://www.gnu.org/licenses/>.
; */

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

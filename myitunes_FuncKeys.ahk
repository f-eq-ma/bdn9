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

; F16 - iTunes pause/play toggle (ctl-space)
F16::
	DetectHiddenWindows , On 
    ; Had to use the {Ctrl down} .. {Ctrl up} syntax due to odd conflicts with QMK
	; was not getting a consistent key presses...
	ControlSend , ahk_parent, {Ctrl down}{SPACE}{Ctrl up}, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return
	
; F19 - iTunes next (ctl-right arrow)
F19::
	DetectHiddenWindows , On 
	ControlSend , ahk_parent, {Ctrl down}{right}{Ctrl up}, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return

; F14 - iTunes back (ctl-left arrow)
F14::
	DetectHiddenWindows , On 
	ControlSend , ahk_parent, {Ctrl down}{left}{Ctrl up}, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return

; F17 - iTunes mini player toggle (ctl-shit-M)	
F17::
	DetectHiddenWindows , On 
	; Above ControlSend syntax did not work...and the below is stable...no clue.
	; Note:  Can take several seconds for iTunes to toggle mini-viewer
	ControlSend , ahk_parent, {Shift}^M, iTunes ahk_class iTunes
	DetectHiddenWindows , Off
	return

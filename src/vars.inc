; Existing variables. Most names are taken from the source of another game the
; original author wrote for similar hardware.

F12Mvw = $F4400  ; Player 2 main shot work
F11Mvw = $F5200  ; Player 1 main shot work
P2Mvw = $F6000  ; Player 2 move work
P1Mvw = $F6300  ; Player 1 move work
GameSt = $F9000
VbFlag = $F9008
HbFlag = $F9006
Credit = $F900C
CoinAM = $F901C
CoinBM = $F901E
StgCtr = $F9022
RndCtr = $F9024
PstFlg = $F902A
SpntOk = $F904C

S1HWait = $F90E0
S1HWait2 = $F90E2
S1VWait = $F90E4
S1VWait2 = $F90E6
SoundCuePtrMax = $F90F8
SoundCuePtr = $F90FC

; These variables are struct offsets, which didn't have names even in the
; original source (he must have used a notepad or text doc).
PlayerMv_DeadFlag = $3C  ; w
PlayerMv_SwitchData = $E  ; w
PlayerMv_ShotMaxCounter = $90
PlayerMv_ShotWaitCounter = $92
PlayerMv_ShotOnFlag = $94
PlayerMv_ShotOnCounter = $64
PlayerMv_ShotAuto


; New variables used during startup (invalidated once program starts).
	ORG	WRAM

PrintVramAddr:
	ds.l	1

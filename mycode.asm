.MODEL SMALL
.STACK 100H
.DATA
NL EQU 0AH,0DH
VAR DB ?
MSG DB NL,"HELLO WORLD",NL,"$"
.CODE
MAIN PROC
     MOV AX,@DATA
     MOV DS,AX
    
     MOV AH,1
     INT 21H
     MOV VAR,AL
     
     MOV AH,2
     MOV DL,0AH
     INT 21H
     MOV DL,0DH
     INT 21H
     
     MOV DL,VAR
     INT 21H
     
     MOV AH,9
     LEA DX,MSG
     INT 21H
        
        
     MOV AH, 4CH
     INT 21H     
MAIN ENDP
    END MAIN
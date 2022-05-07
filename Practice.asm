.MODEL SMALL
.STACK 100H
.DATA
VAR1 DB ?
VAR2 DB ?
VAR3 DB ?
REST DB ?

.CODE
MAIN PROC
     MOV AX,@DATA
     MOV DS,AX
     
     MOV AH,1
     INT 21H
     MOV VAR1,AL
     
     INT 21H
     MOV VAR2,AL
     
     INT 21H
     MOV VAR3,AL
        
     ;NOW WE CALCULATE
     MOV BL,VAR1
     ADD BL,VAR2
     SUB BL,VAR3
     
     ;WE PRINT HERE
     MOV AH,2
     MOV DL,BL
     INT 21H
     
     MOV AH,4CH
     INT 21H
MAIN ENDP
    END MAIN
    
    
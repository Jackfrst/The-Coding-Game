.MODEL SMALL
.STACK 100H

.DATA
NL EQU 0AH,0DH
A DB ?
B DB ?
C DB ?
IN_A DB NL,"ENTER FIRST INPUT : $"
IN_B DB NL,"ENTER SECOND INPUT : $"
IN_C DB NL,"ENTER THIRD INPUT : $" 
NO DB NL,NL," Invalid character $"
OK DB NL,NL," All OK $"

.CODE
MAIN PROC
     MOV AX,@DATA
     MOV DS,AX
         
     MOV AH,9           ; FIRST NUMBER INPUT 
     LEA DX,IN_A
     INT 21H       
     MOV AH,1
     INT 21H
     MOV A,AL
     MOV BL,A
     
     MOV AH,9           ; SECOND NUMBER INPUT 
     LEA DX,IN_B
     INT 21H       
     MOV AH,1
     INT 21H
     MOV B,AL
     MOV BH,B
     
     MOV AH,9           ; THIRD NUMBER INPUT 
     LEA DX,IN_C
     INT 21H       
     MOV AH,1
     INT 21H
     MOV C,AL
     MOV CL,C
     
     CMP BL,30H         ; CHECK
     JL  NONE
     CMP BL,39H
     JG  NONE
     CMP BH,30H
     JL  NONE
     CMP BH,39H
     JG  NONE
     CMP CL,30H
     JL  NONE
     CMP CL,39H
     JG  NONE
     
     MOV AH,9           ;ALL OK
     LEA DX,OK
     INT 21H
     JMP NEXT
     
NONE:
     MOV AH,9           ;NO
     LEA DX,NO
     INT 21H    
    
NEXT:         
     MOV AH,4CH
     INT 21H     
MAIN ENDP   
    END MAIN
    
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
BOTH DB " AND $" 
NO DB NL,NL,"THERE IS NO SECOND LARGEST NUMBER $"
SECOND_LRG DB NL,NL,"THE SECOND LARGEST NUMBER IS : $"

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
     
     CMP BL,BH
     JG  CMP_B_C
     JL  CMP_A_C
     JE  CMP_AB_C
     
CMP_A_C:
     CMP BL,CL
     JG  INT_2A
     JL  INT_2BC
     JE  INT_2_A_C
     INT_2BC:
            CMP BH,CL
            JG  INT_2C
            JL  INT_2B
            JE  INT_2A        
CMP_B_C:
     CMP BH,CL
     JG  INT_2B
     JL  INT_2AC
     JE  INT_2_B_C 
     INT_2AC:
            CMP BL,CL
            JG  INT_2C
            JL  INT_2A
            JE  INT_2B      
CMP_AB_C:
     CMP BL,CL
     JG  INT_2C
     JL  INT_2_A_B
     JE  INT_NO 
          
INT_2A:
     MOV AH,9           
     LEA DX,SECOND_LRG
     INT 21H
     MOV AH,2
     MOV DL,A
     INT 21H
        JMP NEXT
INT_2B:
     MOV AH,9           
     LEA DX,SECOND_LRG
     INT 21H
     MOV AH,2
     MOV DL,B
     INT 21H
        JMP NEXT
INT_2C:
     MOV AH,9           
     LEA DX,SECOND_LRG
     INT 21H
     MOV AH,2
     MOV DL,C
     INT 21H
        JMP NEXT        
INT_2_A_C:
     MOV AH,9           
     LEA DX,SECOND_LRG
     INT 21H
     MOV AH,2
     MOV DL,A
     INT 21H
     MOV AH,9
     LEA DX,BOTH
     INT 21H
     MOV AH,2
     MOV DL,C
     INT 21H
        JMP NEXT
INT_2_A_B:
     MOV AH,9           
     LEA DX,SECOND_LRG
     INT 21H
     MOV AH,2
     MOV DL,A
     INT 21H
     MOV AH,9
     LEA DX,BOTH
     INT 21H
     MOV AH,2
     MOV DL,B
     INT 21H
        JMP NEXT
INT_2_B_C:
     MOV AH,9           
     LEA DX,SECOND_LRG
     INT 21H
     MOV AH,2
     MOV DL,B
     INT 21H
     MOV AH,9
     LEA DX,BOTH
     INT 21H
     MOV AH,2
     MOV DL,C
     INT 21H
        JMP NEXT
INT_NO:
     MOV AH,9           
     LEA DX,NO
     INT 21H
        JMP NEXT
NEXT:         
     MOV AH,4CH
     INT 21H     
MAIN ENDP   
    END MAIN
    
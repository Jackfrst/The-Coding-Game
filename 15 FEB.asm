.MODEL SMALL
.STACK 100H
.DATA
NL EQU 0AH,0DH
IS DB " IS : $"                      ; USING EQU TO CREATE A CONSTANT 
MSG DB "HELLO EVERYONE!!!!",NL,"$"
MSG1 DB "LEST SUM UP AND SUBTITUTE 2 NUMBERS ",NL,"FROM HERE : ",NL,"$"
MSG2 DB "ENTER THE FIRST INPUT : $"
MSG3 DB NL,"ENTER THE SECOND INPUT : $"
MSG4 DB NL,NL,"RESULT FOR $"
VAR1 DB ?
VAR2 DB ?
VAR3 DB ?
RSLT DB ?
RSLT1 DB ?


.CODE 
MAIN PROC
     MOV AX,@DATA
     MOV DS,AX
     
     MOV AH,9
     LEA DX,MSG      ;LEA = LOAD EFFECTIVE ADDRESS
     INT 21H
     
     MOV AH,2
     MOV DL,0AH
     INT 21H
     
     MOV DL,0DH      ;EXTRA NEW LINE 
     INT 21H
     
     MOV AH,9        ;MESSAGE FOR THE USER
     LEA DX,MSG1
     INT 21H
    
     
     MOV AH,2        ;NEWLINE 
     MOV DL,0AH
     INT 21H
     MOV AH,2
     MOV DL,0DH
     INT 21H
     
     MOV AH,9
     LEA DX,MSG2
     INT 21H
     
     MOV AH,1     ;1ST VALUE 
     INT 21H
     MOV VAR1,AL
     MOV CH,VAR1
     SUB CH,30H
     
     MOV AH,9
     LEA DX,MSG3
     INT 21H  
     
     MOV AH,1     ;2ND VALUE 
     INT 21H
     MOV VAR2,AL
     MOV CL,VAR2
     SUB CL,30H
     
     ADD CH,CL    ;ADDITION
     ADD CH,30H
     MOV RSLT,CH
     
     MOV CH,VAR1  ;SUBSTRACTION
     SUB CH,CL
     MOV RSLT1,CH
       
     MOV AH,9
     LEA DX,MSG4
     INT 21H
     
     MOV AH,2
     MOV DL,VAR1
     INT 21H
     
     MOV DL,"+"
     INT 21H
     
     MOV DL,VAR2
     INT 21H
     
     MOV AH,9
     LEA DX,IS
     INT 21H
     
     MOV AH,2
     MOV DL,RSLT
     INT 21H
      
     MOV AH,9
     LEA DX,MSG4
     INT 21H
     
     MOV AH,2
     MOV DL,VAR1
     INT 21H
     
     MOV DL,"-"
     INT 21H
     
     MOV DL,VAR2
     INT 21H
     
     MOV AH,9
     LEA DX,IS
     INT 21H
     
     MOV AH,2
     MOV DL,RSLT1
     INT 21H
     
     
    
           
     MOV AH,4CH
     INT 21H
MAIN ENDP
    END MAIN
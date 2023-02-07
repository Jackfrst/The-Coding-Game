.MODEL SMALL
.STACK 100H
.DATA

.CODE
MAIN PROC
    
    MOV AH,2        ;AH = 2
    MOV DL,'V'      ;DL = 'V' OR 56H
    INT 21H         ;INTERRUPT 21H
    
    ;MOV AH,2
    MOV DL,'U'
    INT 21H    
    
MAIN ENDP
    END MAIN
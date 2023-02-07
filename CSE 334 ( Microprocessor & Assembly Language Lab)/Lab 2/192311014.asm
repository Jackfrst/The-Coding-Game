.MODEL SMALL
.STACK 100H
.DATA 

.CODE
MAIN PROC    
    MOV AH,2
    MOV DL,'M'
    INT 21H    
    MOV DL,'A'
    INT 21H     
    MOV DL,'H'
    INT 21H    
    MOV DL,'F'
    INT 21H    
    MOV DL,'U'
    INT 21H    
    MOV DL,'J'
    INT 21H   
    MOV DL,'U'
    INT 21H   
    MOV DL,'R'
    INT 21H
              
              
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    MOV DL,'R'
    INT 21H    
    MOV DL,'A'
    INT 21H    
    MOV DL,'H'
    INT 21H    
    MOV DL,'M'
    INT 21H    
    MOV DL,'A'
    INT 21H    
    MOV DL,'N'
    INT 21H    
MAIN ENDP
    END MAIN 
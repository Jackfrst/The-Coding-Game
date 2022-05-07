.MODEL SMALL
.STACK 100H
.DATA    

NL EQU 0DH,0AH 
SELECT_OPERATION DB "Select an operation",NL,"(Enter '+' for add, '-' for sub, '*' for mul, '/' for div): $"
INVALID_INPUT DB NL,NL,"Invalid Input$"
FIRST_NUM DB NL,NL,"Enter the first two digit number: $"
SECOND_NUM DB NL,"Enter the second two digit number: $"  
MSG_SUM DB NL,NL,"The value of Sum: $"    
MSG_SUB DB NL,NL,"The value of Sub: $"
MSG_MUL DB NL,NL,"The value of Mul: $"
MSG_NUM1 DB NL,NL,"Enter first number: $"
MSG_NUM2 DB NL,NL,"Enter second number: $"
MSG_DIV DB NL,NL,"The value of Div: $"
MSG_DIV_QUO DB "Quotient=$"
MSG_DIV_REM DB " Remainder=$"

DIGIT1 DB ?
DIGIT2 DB ?
NUM1 DB ?
NUM2 DB ?
RESULT_SUM DB ?  
RESULT_SUB DB ? 
RESULT_MUL DB ?

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 
    
    LEA DX,SELECT_OPERATION
    MOV AH,9
    INT 21H
    MOV AH,1
    INT 21H
    MOV CL,AL   
    CMP CL,"+"
    JE OP_ADDITION 
    CMP CL,"-"
    JE OP_SUBTRACTION
    CMP CL,"*"
    JE OP_MULTIPLICATION
    CMP CL,"/"
    JE OP_DIVISION
    JMP INVALID
     

OP_ADDITION:
    MOV AH,9
    LEA DX,FIRST_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM1,AL
    
    MOV AH,9
    LEA DX,SECOND_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM2,AL
    
    MOV AH,9
    LEA DX,MSG_SUM
    INT 21H
    
    CALL ADDITION
    MOV AL,RESULT_SUM 
    CALL DISPLAY_RESULT
    JMP EXIT
    

OP_SUBTRACTION:
    MOV AH,9
    LEA DX,FIRST_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM1,AL
    
    MOV AH,9
    LEA DX,SECOND_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM2,AL
    
    MOV AH,9
    LEA DX,MSG_SUB
    INT 21H
    
    CALL SUBTRACTION 
    MOV  AL,RESULT_SUB 
    CALL DISPLAY_RESULT
    JMP EXIT

OP_MULTIPLICATION:
    
    MOV AH,9
    LEA DX,FIRST_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM1,AL
    
    MOV AH,9
    LEA DX,SECOND_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM2,AL
    
    MOV AH,9
    LEA DX,MSG_MUL
    INT 21H

    CALL MULTIPLICATION
    MOV  AL,RESULT_MUL 
    CALL DISPLAY_RESULT
    JMP EXIT
    

OP_DIVISION:  
    MOV AH,9
    LEA DX,FIRST_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM1,AL
    
    MOV AH,9
    LEA DX,SECOND_NUM
    INT 21H
    CALL GET_TWO_DIGIT
    MOV NUM2,AL
    
    MOV AH,9
    LEA DX,MSG_DIV
    INT 21H
    CALL DIVISION
    JMP EXIT


INVALID:
    LEA DX,INVALID_INPUT
    MOV AH,9
    INT 21H
    JMP EXIT
    
EXIT:    
    MOV AH,4CH
    INT 21H
         
MAIN ENDP 

GET_TWO_DIGIT PROC
    MOV AH,1
    INT 21H
    MOV DIGIT1,AL
    SUB DIGIT1,30H
    INT 21H
    MOV DIGIT2,AL
    SUB DIGIT2,30H
    MOV AL,10
    MUL DIGIT1
    ADD AL,DIGIT2
    RET 
GET_TWO_DIGIT ENDP

ADDITION PROC
    MOV BL,NUM1
    ADD BL,NUM2
    MOV RESULT_SUM,BL
    RET   
ADDITION ENDP 

SUBTRACTION PROC
    MOV BL,NUM1
    SUB BL,NUM2
    MOV RESULT_SUB,BL
    RET   
SUBTRACTION ENDP 

MULTIPLICATION PROC
    MOV AL,NUM1
    CBW
    MUL NUM2 
    MOV DIGIT1,AL
    MOV DIGIT2,AH  
    MOV AL,DIGIT1
    MOV RESULT_MUL,AL 
    RET 
MULTIPLICATION ENDP 

DIVISION PROC 
    MOV AL,NUM1
    CBW     
    DIV NUM2 
    MOV DIGIT1,AL
    MOV DIGIT2,AH  
    ADD DIGIT1,30H
    ADD DIGIT2,30H
    MOV AH,9
    LEA DX,MSG_DIV_QUO
    INT 21H 
    MOV AH,2
    MOV DL,DIGIT1
    INT 21H 
    LEA DX,MSG_DIV_REM
    MOV AH,9
    INT 21H   
    MOV AH,2
    MOV DL,DIGIT2
    INT 21H
    RET 
DIVISION ENDP 
 
DISPLAY_RESULT PROC
    CBW
    MOV BL,10       
    DIV BL 
    MOV DIGIT1,AL
    MOV DIGIT2,AH  
    ADD DIGIT1,30H
    ADD DIGIT2,30H
    MOV AH,2
    MOV DL,DIGIT1
    INT 21H
    MOV AH,2
    MOV DL,DIGIT2
    INT 21H
    RET   
DISPLAY_RESULT ENDP
    END MAIN
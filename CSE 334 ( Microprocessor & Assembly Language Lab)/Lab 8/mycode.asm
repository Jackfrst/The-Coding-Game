.MODEL SMALL
.STACK 100H
.DATA
NL EQU 0DH,0AH
ARR DB 100 DUP(?)
INPUT1 DB "ENTER THE FIRST TWO DIGIT NUMBER  : $"
INPUT2 DB NL,"ENTER THE SECOND TWO DIGIT OF NUMBER : $"
VIEW1 DB NL,"THE FIRST NUMBER  : $"
VIEW2 DB NL,"THE SECOND NUMBER : $"
RESULTM DB NL,"THE RESULT IS : $"
DIGIT1 DB ?
DIGIT2 DB ?
NUMBER1 DB ?
NUMBER2 DB ?
RESULT DB ?
.CODE
MAIN PROC
        MOV AX,@DATA
        MOV DS,AX
        
        MOV AH,9
        LEA DX,INPUT1
        INT 21H 
        CALL SOME
        MOV NUMBER1,BL
        
        MOV AH,9
        LEA DX,INPUT2
        INT 21H
        CALL SOME 
        MOV NUMBER2,BL
        
        MOV BL,NUMBER1
        ADD BL,NUMBER2
        MOV RESULT,BL
        
        MOV AH,9
        LEA DX,VIEW1
        INT 21H
        MOV AL,NUMBER1
        CALL SOME1
        
        MOV AH,9
        LEA DX,VIEW2
        INT 21H
        MOV AL,NUMBER2
        CALL SOME1
        
        MOV AH,9
        LEA DX,RESULTM
        INT 21H
        MOV AL,RESULT
        CALL SOME1     
            
        MOV AH,4CH
        INT 21H
  MAIN ENDP

SOME PROC
    MOV AH,1
    INT 21H
    MOV DIGIT1,AL
    SUB DIGIT1,30H
    
    INT 21H
    MOV DIGIT2,AL
    SUB DIGIT2,30H
    
    MOV BL,DIGIT1
    MOV AL,10
    MUL BL
    XOR BL,BL
    MOV BL,AL
    ADD BL,DIGIT2
  RET
    SOME ENDP 

SOME1 PROC
    CBW
    MOV BL,10
    DIV BL
    MOV CH,AH
    MOV CL,AL
    
    XOR AX,AX
    MOV AH,2
    ADD CL,30H
    MOV DL,CL
    INT 21H
    
    ADD CH,30H
    MOV DL,CH
    INT 21H
    RET
    SOME1 ENDP 

END MAIN
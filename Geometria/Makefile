MAIN=main
DIRECCION=direccion
ESFERA=esfera
MATRIX=matrix
OPERACIONES=operaciones
PUNTO=punto
TRANSFORMACIONES=transformaciones


target=${MAIN}

RM = rm -rf
CPP=g++ -std=c++11

.PHONY: all

all: ${target}


${MAIN}: ${MAIN}.o ${DIRECCION}.o ${PUNTO}.o ${MATRIX}.o ${OPERACIONES}.o  ${TRANSFORMACIONES}.o ${ESFERA}.o   
	${CPP} ${DIRECCION}.o ${PUNTO}.o ${MATRIX}.o ${OPERACIONES}.o ${TRANSFORMACIONES}.o ${ESFERA}.o ${MAIN}.o -o ${MAIN}
    
${MAIN}.o: ${MAIN}.cpp 
	${CPP} -c ${MAIN}.cpp

${DIRECCION}.o: ${DIRECCION}.h ${DIRECCION}.cpp
	${CPP} -c ${DIRECCION}.cpp

${PUNTO}.o: ${PUNTO}.h ${PUNTO}.cpp
	${CPP} -c ${PUNTO}.cpp 

${MATRIX}.o: ${MATRIX}.h ${MATRIX}.cpp
	${CPP} -c ${MATRIX}.cpp

${OPERACIONES}.o: ${OPERACIONES}.h ${OPERACIONES}.cpp
	${CPP} -c ${OPERACIONES}.cpp 

${TRANSFORMACIONES}.o: ${TRANSFORMACIONES}.h ${TRANSFORMACIONES}.cpp
	${CPP} -c ${TRANSFORMACIONES}.cpp

${ESFERA}.o: ${ESFERA}.h ${ESFERA}.cpp
	${CPP} -c ${ESFERA}.cpp 

clean:
	$(RM) *.gch
	$(RM) ${target}


# DO NOT DELETE
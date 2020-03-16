.PHONY: clean

make: createLib createBin

createLib:
		cd lib && make
		
createBin:
		cd src && make

clean:
		cd lib && rm libMathOwn.a libMathOwn.so
		cd bin && rm calculadoraExecDynamic calculadoraExecStatic
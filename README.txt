

Modify the 'env.sh' in this folder

Change the 'export PATH' to your path.

==================

step 1:
cd to the project path, e.g. projectName

	cd projectName

step 2:
load the enviroment script, use '.<space><path to env.sh>'

	. ../env.sh

step 3:
create the Makefile

	progen -o projectName.pro
	tmake projectName.pro -o Makefile

step 4:
	make


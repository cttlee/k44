export PATH=$PATH:/home/cttlee/projects/k44/cov-analysis-linux64-2019.03/bin
make x86_64_defconfig
cov-configure --comptype gcc --compiler gcc --template
cov-build --dir cov-int make -j8
zip -r k44.zip cov-int 

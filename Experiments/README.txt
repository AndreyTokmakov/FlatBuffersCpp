
--------------------------------------------------------------------------------------

cd /home/andtokm/DiskS/ProjectsUbuntu/Flatbuffers

git clone git@github.com:google/flatbuffers.git

cmake -G "Unix Makefiles"
make -j6

--------------------------------------------------------------------------------------

cd /home/andtokm/DiskS/ProjectsUbuntu/Flatbuffers/FlatbuffersCPP/Experiments/scheme

../../flatbuffers/flatc --cpp client.fbs
../../flatbuffers/flatc --cpp server.fbs
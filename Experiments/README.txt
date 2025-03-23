==============================================================================================================
                        Get sources
==============================================================================================================

cd /home/andtokm/DiskS/ProjectsUbuntu/Flatbuffers
git clone git@github.com:google/flatbuffers.git

==============================================================================================================
                        Build  | https://flatbuffers.dev/building/
=============================================================================================================

cmake -G "Unix Makefiles"
make -j6

==============================================================================================================
                        Usage  | https://flatbuffers.dev/flatc/
=============================================================================================================

/home/andtokm/DiskS/ProjectsUbuntu/Flatbuffers/flatbuffers/flatc --cpp message.fbs
/home/andtokm/DiskS/ProjectsUbuntu/Flatbuffers/flatbuffers/flatc --cpp --no-prefix --scoped-enums message.fbs


    --no-prefix    : Don't prefix enum values in generated C++ by their enum type.
    --scoped-enums : Use C++11 style scoped and strongly typed enums in generated C++. This also implies --no-prefix.
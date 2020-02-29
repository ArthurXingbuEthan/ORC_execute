#include "orc.h"
// JANK FIX: Please find better way unless this is best
#include "orcloader.cpp"

#include <iostream>
#include <vector>

typedef unordered_map<size_t,memory_value>::const_iterator map_iter;

using namespace std;

struct instruction{
    public:
    std::string value;
    int type;
    std::string firstcode;
    std::string opcode;
    std::string name;
    std::string src;
    std::string dest;
    std::string val;
    std::string toString(){
        return (this->name + "+" + this->value);
    }
};



void OrcRunner::printListOfStrings() const{
    ofstream printListOfInstrBinary;
    printListOfInstrBinary.open("instrBinary.txt");
    for(size_t i = 0; i <this->listOfInstructionStrings.size(); i++){
        //cout << this->listOfInstructionStrings[i] << endl;
        printListOfInstrBinary << this->listOfInstructionStrings[i] << endl;
    }
    printListOfInstrBinary.close();
}

ostream & operator << (ostream &out, const permissions & p) {
        out << ( (p.readable())?"Re":"  " ) << ( (p.writeable())?"Wr":"  " ) << ( (p.executable())?"Ex":"  " );
        return out;
}
ostream & operator << (ostream &out, const memory_value & m) {
        out << ((m.value!=0)?(char)m.value:' ') << " : " << bitset<7>(m.value).to_string() << " : " << m.p;
        return out;
}

OrcRunner::OrcRunner() { }

OrcRunner::OrcRunner(const Orc & orc) {
    OrcRunner in = OrcLoader().getOrcRunner(orc);
    MEMORY = unordered_map<size_t,memory_value>(in.MEMORY);
    entryPoint = in.entryPoint;

    filename = orc.getFilename();
}

instruction interpretInstructionType1(std::string fullinstruction){
    instruction i;
    i.value = fullinstruction;
    i.type = 1;
    i.firstcode = fullinstruction.substr(0,3);
    i.opcode = fullinstruction.substr(3,4);
    switch(stoi(i.opcode, NULL,2)){
        case 0:
            i.name = "ADD";
            break;
        case 1:
            i.name = "SUB";
            break;
        case 2:
            i.name = "MUL";
            break;
        case 3:
            i.name = "DIV";
            break;
        case 4:
            i.name = "CMP";
            break;
        case 5:
            i.name = "TST";
            break;
        case 6:
            i.name = "AND";
            break;
        case 7:
            i.name = "ORR";
            break;
        case 8:
            i.name = "XOR";
            break;
        case 9:
            i.name = "STR";
            break;
        case 10:
            i.name = "STB";
            break;
        case 11:
            i.name = "LOD";
            break;
        default:
            i.name = "NAN";
            break;
        }
    if(i.opcode == "010"){  
        i.src = fullinstruction.substr(7,4);
        i.dest = fullinstruction.substr(11,4);
    }
    else if(i.opcode == "011"){
        i.src = fullinstruction.substr(14);
        i.dest = fullinstruction.substr(7,4);
    }
    return i;
    
}

instruction interpretInstructionType2(std::string fullinstruction){
    instruction i;
    i.value = fullinstruction;
    i.type = 2;
    i.firstcode = fullinstruction.substr(0,3);
    i.opcode = fullinstruction.substr(3,4);
    switch(stoi(i.opcode, NULL,2)){
        case 0:
            i.name = "JMP";
            break;
        case 1:
            i.name = "JLT";
            break;
        case 2:
            i.name = "JEQ";
            break;
        case 3:
            i.name = "CAL";
            break;
        case 4:
            i.name = "PSH";
            break;
        case 5:
            i.name = "POP";
            break;
        case 6:
            i.name = "NOT";
            break;
        case 7:
            i.name = "OUT";
            break;
        case 8:
            i.name = "INP";
            break;
        case 9:
            i.name = "AMP";
            break;
        case 10:
            i.name = "ALT";
            break;
        case 11:
            i.name = "AEQ";
            break;
        case 12:
            i.name = "AAL";
            break;
        default:
            i.name = "NAN";
            break;
        }
    if(i.opcode == "100"){  
        i.val = fullinstruction.substr(7,4);
    }
    else if(i.opcode == "101"){
        i.val = fullinstruction.substr(7);
    }
    return i;
    
}

//function returns where the next starting location should be
size_t interpretAndWrite(std::string firstLineOfOper, size_t indexInMem, std::unordered_map<size_t,memory_value>& mem, ofstream& printer){
    cout << "in interpret and write, indexInMem: " << indexInMem << endl;



    
    instruction instr;
    bool instructionParsed = 0;
    size_t returnValue = indexInMem;


    if(firstLineOfOper == ""){
        cout << "in interpretAndWrite, instruction string is NULL";
        return -1;
    }
    std::string firstCode = firstLineOfOper.substr(0,3);
    if(firstCode == "010"){
        std::string fullInstr = bitset<7>(mem.at(indexInMem).value).to_string() + bitset<7>(mem.at(indexInMem+1).value).to_string() + bitset<7>(mem.at(indexInMem+2).value).to_string();
        returnValue += 3;
        instr = interpretInstructionType1(fullInstr);
        instructionParsed = 1;
    }
    else if(firstCode == "011"){
        std::string fullInstr = bitset<7>(mem.at(indexInMem).value).to_string() + bitset<7>(mem.at(indexInMem+1).value).to_string() + bitset<7>(mem.at(indexInMem+2).value).to_string() + bitset<7>(mem.at(indexInMem+3).value).to_string() + bitset<7>(mem.at(indexInMem+4).value).to_string() + bitset<7>(mem.at(indexInMem+5).value).to_string();
        returnValue += 6;
        instr = interpretInstructionType1(fullInstr);
        instructionParsed = 1;
    }
    else if(firstCode == "100"){
        std::string fullInstr = bitset<7>(mem.at(indexInMem).value).to_string() + bitset<7>(mem.at(indexInMem+1).value).to_string();
        returnValue += 2;
        instr = interpretInstructionType2(fullInstr);
        instructionParsed = 1;
    }
    else if(firstCode == "101"){
        std::string fullInstr = bitset<7>(mem.at(indexInMem).value).to_string() + bitset<7>(mem.at(indexInMem+1).value).to_string() + bitset<7>(mem.at(indexInMem+2).value).to_string() + bitset<7>(mem.at(indexInMem+3).value).to_string() + bitset<7>(mem.at(indexInMem+4).value).to_string();
        returnValue += 5;
        instr = interpretInstructionType2(fullInstr);
        instructionParsed = 1;
    }
    else{
        std::string errorMsg = "reached an instruction that cannot be parsed, firstCode: " + (firstCode);
        cout << errorMsg << endl;
        printer << errorMsg << endl;
    }




    if(instructionParsed) printer << instr.toString() << endl;
    return returnValue;
}

// this will be the meaty function
// run the operation that you find, change MI to next operation
void OrcRunner::execute()  {
    ofstream ofs_full;
    ofstream ofs_limited;
    ofstream printer;
    std::string desired_filename_full = filename + ".exe.txt";
    std::string desired_filename_lim = "out_limited_1.txt";
    desired_filename_full = "output1.txt";
    ofs_full.open(desired_filename_full);
    ofs_limited.open(desired_filename_lim);
    printer.open("instructionLog.txt");


    // YO! You are allowed to do this! That way you don't have to do "MEMORY.at(40).value"
    // int a = MEMORY.at(40);



    // currently just prints all memory addresses
    for (map_iter it = MEMORY.begin(); it != MEMORY.end(); it++ ){
        ofs_full << ((it->first > 99)?"":" ") << it->first << ": " << it->second << endl;
        ofs_limited << it->first << ":" << bitset<7>(it->second.value).to_string() << endl;
        std::string res = bitset<7>(it->second.value).to_string();
        if(it->second.p.executable()) this->listOfInstructionStrings.push_back(res); 
    }
    size_t currentIndex = entryPoint;
    //cout << "starting element: " << bitset<7>(MEMORY.at(currentIndex).value).to_string() << endl;

    printListOfStrings();

    while(MEMORY.find(currentIndex) != MEMORY.end()){
        size_t nextLoc = interpretAndWrite(bitset<7>(MEMORY.at(currentIndex).value).to_string(), currentIndex, MEMORY, printer);
        if(nextLoc == currentIndex){
            cout << "interpreter returned the same location, check log" << endl;
            break;
        }
        else currentIndex = nextLoc;
    }

    ofs_full.close();
    ofs_limited.close();
    printer.close();
}


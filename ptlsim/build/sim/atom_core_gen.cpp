/*
 * DO NOT MODIFY
 * This file is atuomatically generated by Marss Builder.
 * If you want to make any changes to this configuration please make
 * changes to '.conf' file which was used to generate this.
 * 
 * conf file: /home/kkm0411/marss.dramsim_2/config/default.conf
 */



#include <globals.h>
#include <machine.h>
#include <basecore.h>
#include <memoryHierarchy.h>
#include <cpuController.h>


using namespace Core;
using namespace Memory;


int atom_core_handle_cpuid(uint32_t index, uint32_t count, uint32_t *eax, uint32_t *ebx,
        uint32_t *ecx, uint32_t *edx)
{


    uint32_t cores_info =
        (((0) << 14) & 0x3fc000) |
        (((NUMBER_OF_CORES - 1) << 26) & 0xfc00000);

    switch (index) {
        case 4:
            switch (count) {
                case 0: { // L1-D cache info
                            *eax = 0x121 | cores_info;
                            *ebx = ((64 & 0xfff) |
                                    ((64 << 12) & 0x3ff000) |
                                    ((8 << 22) & 0xffc00000) );
                            *ecx = 256;
                            *edx = 0x1;
                            break;
                        }
                case 1: { // L1-I cache info
                            *eax = 0x122 | cores_info;
                            *ebx = ((64 & 0xfff) |
                                    ((64 << 12) & 0x3ff000) |
                                    ((8 << 22) & 0xffc00000) );
                            *ecx = 256;
                            *edx = 0x1;
                            break;
                        }
                case 2: { // L2 cache info
                            uint32_t l2_core_info =
                                ((((NUMBER_OF_CORES)/1) << 14) &
                                 0x3fc000);
                            l2_core_info |= ((NUMBER_OF_CORES - 1) << 26) &
                                0xfc00000;
                            *eax = 0x143 | l2_core_info;
                            *ebx = ((64 & 0xfff) |
                                    ((64 << 12) & 0x3ff000) |
                                    ((8 << 22) & 0xffc00000) );
                            *ecx = 4096;
                            *edx = 0x1;
                            break;
                        }
                
                default: {
                             *eax = 0;
                             *ebx = 0;
                             *ecx = 0;
                             *edx = 0;
                         }
            }
            break;
        default:
            /* unsupported CPUID */
            return 0;
    }

    return 1;
}


void gen_atom_core_machine(BaseMachine& machine)
{


    while(!machine.context_used.allset()) {

        machine.add_option("atom_", machine.coreid_counter, "threads", 1);

        CoreBuilder::add_new_core(machine, "atom_", "atom");
        if (machine.context_used.allset()) break;

    }


    foreach(i, machine.get_num_cores()) {

        ControllerBuilder::add_new_cont(machine, i, "core_", "cpu", 0);

    }


    foreach(i, machine.get_num_cores()) {

        ControllerBuilder::add_new_cont(machine, i, "L1_I_", "wb_cache", L1_128K);

    }


    foreach(i, machine.get_num_cores()) {

        ControllerBuilder::add_new_cont(machine, i, "L1_D_", "wb_cache", L1_128K);

    }


    foreach(i, 1) {

        ControllerBuilder::add_new_cont(machine, i, "L2_", "wb_cache", L2_2M);

    }


    foreach(i, 1) {

        machine.add_option("MEM_", i, "latency", 50);

        ControllerBuilder::add_new_cont(machine, i, "MEM_", "simple_dram_cont", 0);

    }


    foreach(i, machine.get_num_cores()) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_core_L1_I_", i);


        stringbuf core_;
        core_ << "core_" << i;
        machine.add_new_connection(connDef, core_.buf, INTERCONN_TYPE_I);


        stringbuf L1_I_;
        L1_I_ << "L1_I_" << i;
        machine.add_new_connection(connDef, L1_I_.buf, INTERCONN_TYPE_UPPER);


        Controller** cont = machine.controller_hash.get(core_);
        assert(cont);
        CPUController* cpuCont = (CPUController*)((*cont));
        cpuCont->set_icacheLineBits(log2(64));

    }


    foreach(i, machine.get_num_cores()) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_core_L1_D_", i);


        stringbuf core_;
        core_ << "core_" << i;
        machine.add_new_connection(connDef, core_.buf, INTERCONN_TYPE_D);


        stringbuf L1_D_;
        L1_D_ << "L1_D_" << i;
        machine.add_new_connection(connDef, L1_D_.buf, INTERCONN_TYPE_UPPER);


        Controller** cont = machine.controller_hash.get(core_);
        assert(cont);
        CPUController* cpuCont = (CPUController*)((*cont));
        cpuCont->set_dcacheLineBits(log2(64));

    }


    foreach(i, 1) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_L1_I_0_L2_0", i);


        stringbuf L1_I_0;
        L1_I_0 << "L1_I_0";
        machine.add_new_connection(connDef, L1_I_0.buf, INTERCONN_TYPE_LOWER);


        stringbuf L2_0;
        L2_0 << "L2_0";
        machine.add_new_connection(connDef, L2_0.buf, INTERCONN_TYPE_UPPER);


    }


    foreach(i, 1) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_L2_0_L1_D_0", i);


        stringbuf L2_0;
        L2_0 << "L2_0";
        machine.add_new_connection(connDef, L2_0.buf, INTERCONN_TYPE_UPPER2);


        stringbuf L1_D_0;
        L1_D_0 << "L1_D_0";
        machine.add_new_connection(connDef, L1_D_0.buf, INTERCONN_TYPE_LOWER);


    }


    foreach(i, 1) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_L2_0_MEM_0", i);


        stringbuf L2_0;
        L2_0 << "L2_0";
        machine.add_new_connection(connDef, L2_0.buf, INTERCONN_TYPE_LOWER);


        stringbuf MEM_0;
        MEM_0 << "MEM_0";
        machine.add_new_connection(connDef, MEM_0.buf, INTERCONN_TYPE_UPPER);


    }


    machine.handle_cpuid = &atom_core_handle_cpuid;


    machine.setup_interconnects();
    machine.memoryHierarchyPtr->setup_full_flags();
}

MachineBuilder atom_core("atom_core", &gen_atom_core_machine);

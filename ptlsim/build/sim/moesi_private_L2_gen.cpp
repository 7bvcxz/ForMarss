/*
 * DO NOT MODIFY
 * This file is atuomatically generated by Marss Builder.
 * If you want to make any changes to this configuration please make
 * changes to '.conf' file which was used to generate this.
 * 
 * conf file: /home/kkm0411/marss.dramsim_2/config/moesi.conf
 */



#include <globals.h>
#include <machine.h>
#include <basecore.h>
#include <memoryHierarchy.h>
#include <cpuController.h>


using namespace Core;
using namespace Memory;


int moesi_private_L2_handle_cpuid(uint32_t index, uint32_t count, uint32_t *eax, uint32_t *ebx,
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
                                (((1) << 14) &
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
                
                case 3: { // L3 cache info
                            uint32_t l3_core_info =
                                (((NUMBER_OF_CORES) << 14) &
                                 0x3fc000);
                            l3_core_info |= ((NUMBER_OF_CORES - 1) << 26) &
                                0xfc00000;
                            *eax = 0x163 | l3_core_info;
                            *ebx = ((64 & 0xfff) |
                                    ((64 << 12) & 0x3ff000) |
                                    ((8 << 22) & 0xffc00000) );
                            *ecx = 16384;
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


void gen_moesi_private_L2_machine(BaseMachine& machine)
{


    while(!machine.context_used.allset()) {

        CoreBuilder::add_new_core(machine, "ooo_", "ooo");
        if (machine.context_used.allset()) break;

    }


    foreach(i, machine.get_num_cores()) {

        ControllerBuilder::add_new_cont(machine, i, "core_", "cpu", 0);

    }


    foreach(i, machine.get_num_cores()) {

        machine.add_option("L1_I_", i, "private", true);

        ControllerBuilder::add_new_cont(machine, i, "L1_I_", "moesi_cache", L1_128K_MOESI);

    }


    foreach(i, machine.get_num_cores()) {

        machine.add_option("L1_D_", i, "private", true);

        ControllerBuilder::add_new_cont(machine, i, "L1_D_", "moesi_cache", L1_128K_MOESI);

    }


    foreach(i, machine.get_num_cores()) {

        machine.add_option("L2_", i, "last_private", true);

        machine.add_option("L2_", i, "private", true);

        ControllerBuilder::add_new_cont(machine, i, "L2_", "moesi_cache", L2_2M_MOESI);

    }


    foreach(i, 1) {

        machine.add_option("L3_", i, "private", false);

        ControllerBuilder::add_new_cont(machine, i, "L3_", "wb_cache", L3_8M);

    }


    foreach(i, 1) {

        ControllerBuilder::add_new_cont(machine, i, "DIR_", "global_dir", 0);

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


    foreach(i, machine.get_num_cores()) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_L1_I_L2_", i);


        stringbuf L1_I_;
        L1_I_ << "L1_I_" << i;
        machine.add_new_connection(connDef, L1_I_.buf, INTERCONN_TYPE_LOWER);


        stringbuf L2_;
        L2_ << "L2_" << i;
        machine.add_new_connection(connDef, L2_.buf, INTERCONN_TYPE_UPPER);


    }


    foreach(i, machine.get_num_cores()) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_L1_D_L2_", i);


        stringbuf L1_D_;
        L1_D_ << "L1_D_" << i;
        machine.add_new_connection(connDef, L1_D_.buf, INTERCONN_TYPE_LOWER);


        stringbuf L2_;
        L2_ << "L2_" << i;
        machine.add_new_connection(connDef, L2_.buf, INTERCONN_TYPE_UPPER2);


    }


    foreach(i, 1) {

        ConnectionDef* connDef = machine.get_new_connection_def("p2p",
                "p2p_L3_0_MEM_0", i);


        stringbuf L3_0;
        L3_0 << "L3_0";
        machine.add_new_connection(connDef, L3_0.buf, INTERCONN_TYPE_LOWER);


        stringbuf MEM_0;
        MEM_0 << "MEM_0";
        machine.add_new_connection(connDef, MEM_0.buf, INTERCONN_TYPE_UPPER);


    }


    foreach(i, 1) {

        ConnectionDef* connDef = machine.get_new_connection_def("switch",
                "switch_0", i);


        foreach(j, machine.get_num_cores()) {

            stringbuf L2_;
            L2_ << "L2_" << j;
            machine.add_new_connection(connDef, L2_.buf, INTERCONN_TYPE_LOWER);


        }


        stringbuf L3_0;
        L3_0 << "L3_0";
        machine.add_new_connection(connDef, L3_0.buf, INTERCONN_TYPE_UPPER);


        stringbuf DIR_0;
        DIR_0 << "DIR_0";
        machine.add_new_connection(connDef, DIR_0.buf, INTERCONN_TYPE_DIRECTORY);


    }


    machine.handle_cpuid = &moesi_private_L2_handle_cpuid;


    machine.setup_interconnects();
    machine.memoryHierarchyPtr->setup_full_flags();
}

MachineBuilder moesi_private_L2("moesi_private_L2", &gen_moesi_private_L2_machine);

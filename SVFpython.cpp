#include <pybind11/pybind11.h>
#include "SVFpython.h"

namespace py = pybind11;

PYBIND11_MODULE(py_svf, m) {
    m.doc() = "Module for providing python bindings for the SVF library";

    m.def("getLLVMModuleSet", &SVF::LLVMModuleSet::getLLVMModuleSet);
    m.def("releaseLLVMModuleSet", &SVF::LLVMModuleSet::releaseLLVMModuleSet);
    m.def("buildSVFModule", py::overload_cast<const std::vector<std::string> &> (&SVF::LLVMModuleSet::buildSVFModule) );

    m.def("getModuleIdentifier", &SVF::SVFModule::getModuleIdentifier);
}
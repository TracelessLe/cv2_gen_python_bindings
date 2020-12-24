static PyObject* pyopencv_qy_fillHoles(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace qy;

    {
    PyObject* pyobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fillHoles", (char**)keywords, &pyobj_mat) &&
        pyopencv_to(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(qy::fillHoles(mat));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fillHoles", (char**)keywords, &pyobj_mat) &&
        pyopencv_to(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(qy::fillHoles(mat));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}


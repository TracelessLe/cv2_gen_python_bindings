//================================================================================
// Filters (Generic)
//================================================================================

// GetSet (Filters)



// Methods (Filters)

static int pyopencv_qy_Filters_Filters(pyopencv_Filters_t* self, PyObject* args, PyObject* kw)
{
    using namespace qy;


    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<qy::Filters>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new qy::Filters()));
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_qy_Filters_edge(PyObject* self, PyObject* args, PyObject* kw)
{
    using namespace qy;


    Ptr<qy::Filters> * self1 = 0;
    if (!pyopencv_Filters_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Filters' or its derivative)");
    Ptr<qy::Filters> _self_ = *(self1);
    {
    PyObject* pyobj_im = NULL;
    Mat im;
    PyObject* pyobj_imedge = NULL;
    Mat imedge;

    const char* keywords[] = { "im", "imedge", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:Filters.edge", (char**)keywords, &pyobj_im, &pyobj_imedge) &&
        pyopencv_to(pyobj_im, im, ArgInfo("im", 0)) &&
        pyopencv_to(pyobj_imedge, imedge, ArgInfo("imedge", 1)) )
    {
        ERRWRAP2(_self_->edge(im, imedge));
        return pyopencv_from(imedge);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_im = NULL;
    UMat im;
    PyObject* pyobj_imedge = NULL;
    UMat imedge;

    const char* keywords[] = { "im", "imedge", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:Filters.edge", (char**)keywords, &pyobj_im, &pyobj_imedge) &&
        pyopencv_to(pyobj_im, im, ArgInfo("im", 0)) &&
        pyopencv_to(pyobj_imedge, imedge, ArgInfo("imedge", 1)) )
    {
        ERRWRAP2(_self_->edge(im, imedge));
        return pyopencv_from(imedge);
    }
    }

    return NULL;
}



// Tables (Filters)

static PyGetSetDef pyopencv_Filters_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_Filters_methods[] =
{
    {"edge", CV_PY_FN_WITH_KW_(pyopencv_qy_Filters_edge, 0), "edge(im[, imedge]) -> imedge\n."},

    {NULL,          NULL}
};

// Converter (Filters)

template<>
struct PyOpenCV_Converter< Ptr<qy::Filters> >
{
    static PyObject* from(const Ptr<qy::Filters>& r)
    {
        return pyopencv_Filters_Instance(r);
    }
    static bool to(PyObject* src, Ptr<qy::Filters>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<qy::Filters> * dst_;
        if (pyopencv_Filters_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<qy::Filters> for argument '%s'", info.name);
        return false;
    }
};


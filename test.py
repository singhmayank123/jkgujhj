import os
os.environ["ENFLAME_ENABLE_PT_DYNAMIC_SHAPE"] = "true"
import unittest
import torch_gcu
import torch
import logging
logging.basicConfig(level = logging.INFO)
import torch.nn.functional as F

dev = torch_gcu.gcu_device(0)
class HlirBridgeOpsTest(unittest.TestCase):

    def test_index_copy(self):
        test_dtypes = [torch.float32]
        test_shapes = [(1,), (3,4)]
        for tdtype in test_dtypes:
            for tshape in test_shapes:
                c_input = torch.randn(tshape).to(tdtype)
                d_input = c_input.to(dev)
                c_source = torch.randn(tshape).to(tdtype)
                d_source = c_source.to(dev)

                # Create a valid index tensor for the specified dimension (dim)
                dim = len(tshape) - 1
                c_index = torch.randint(tshape[dim], size=(tshape[dim],), dtype=torch.int64)
                d_index = c_index.to(dev)

                c_output = torch.index_copy(c_input, dim, c_index, c_source).to(tdtype)
                d_output = torch.index_copy(d_input, dim, d_index, d_source).cpu()
                logging.info("CINPUT - %s", c_output)
                logging.info("DINPUT - %s", d_output)

                self.assertTrue(torch.allclose(c_output, d_output))

        print(torch_gcu.metrics_report())

    def test_index_add(self):
        test_dtypes = [torch.float32]
        test_shapes = [(1,), (3,4)]
        for tdtype in test_dtypes:
            for tshape in test_shapes:
                c_input = torch.randn(tshape).to(tdtype)
                d_input = c_input.to(dev)
                c_source = torch.randn(tshape).to(tdtype)
                d_source = c_source.to(dev)

                # Create a valid index tensor for the specified dimension (dim)
                dim = len(tshape) - 1
                c_index = torch.randint(tshape[dim], size=(tshape[dim],), dtype=torch.int64)
                d_index = c_index.to(dev)

                c_output = torch.index_add(c_input, dim, c_index, c_source).to(tdtype)
                d_output = torch.index_add(d_input, dim, d_index, d_source).cpu()

                logging.info("CINPUT - %s", c_output)
                logging.info("DINPUT - %s", d_output)

                self.assertTrue(torch.allclose(c_output, d_output))

        print(torch_gcu.metrics_report())

    def test_index_fill(self):
        test_dtypes = [torch.float32]
        test_shapes = [(1,)]
        for tdtype in test_dtypes:
            for tshape in test_shapes:
                c_input = torch.randn(tshape).to(tdtype)
                d_input = c_input.to(dev)
                
                c_source = torch.randn(tshape)[0].to(tdtype)
                d_source = c_source.to(dev)

                # Create a valid index tensor for the specified dimension (dim)
                dim = len(tshape) - 1
                c_index = torch.randint(tshape[dim], size=(tshape[dim],), dtype=torch.int64)
                d_index = c_index.to(dev)

                c_output = torch.index_fill(c_input, dim, c_index, c_source).to(tdtype)
                d_output = torch.index_fill(d_input, dim, d_index, d_source).cpu()

                logging.info("CINPUT - %s", c_output)
                logging.info("DINPUT - %s", d_output)

                self.assertTrue(torch.allclose(c_output, d_output))

        print(torch_gcu.metrics_report())

                                                                                                            
import typescript from '@rollup/plugin-typescript';
import dts from "rollup-plugin-dts";
import del from "rollup-plugin-delete";

export default [
    {
        input: 'src/index.ts',
        output: [
            {
                file: 'index.cjs',
                format: 'cjs',
                sourcemap: 'inline'
            },
            {
                file: 'index.mjs',
                format: 'esm',
                sourcemap: 'inline'
            }
        ],
        plugins: [
            typescript(),
        ]
    },
    {
        input: "src/types/index.d.ts",
        output: [{
            file: "index.d.ts",
            format: "es",
            plugins: []
        }],
        plugins: [      
            dts(),
            del({ targets: "dist/types", hook: "buildEnd" })
        ],
    }
]
FROM devkitpro/devkitarm:latest AS main_builder
WORKDIR /app

COPY . .
RUN make

FROM scratch AS exporter
COPY --from=main_builder /app/patito-cuac-cuac-nds.nds /patito-cuac-cuac-nds.nds